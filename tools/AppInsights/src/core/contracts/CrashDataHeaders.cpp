#include "CrashDataHeaders.h"

using namespace ApplicationInsights::core;

CrashDataHeaders::CrashDataHeaders() :
    m_processId(0),
    m_parentProcessId(0),
    m_crashThread(0)
{
}

CrashDataHeaders::~CrashDataHeaders()
{
}

void CrashDataHeaders::Serialize(Serializer& serializer) const
{
    serializer.WritePropertyName(L"id");
    serializer.WriteStringValue(m_id);
    
    if (!m_process.empty())
    {
        serializer.WritePropertyName(L"process");
        serializer.WriteStringValue(m_process);
    }
    
    serializer.WritePropertyName(L"processId");
    serializer.WriteIntegerValue(m_processId);
    
    if (!m_parentProcess.empty())
    {
        serializer.WritePropertyName(L"parentProcess");
        serializer.WriteStringValue(m_parentProcess);
    }
    
    serializer.WritePropertyName(L"parentProcessId");
    serializer.WriteIntegerValue(m_parentProcessId);
    
    serializer.WritePropertyName(L"crashThread");
    serializer.WriteIntegerValue(m_crashThread);
    
    if (!m_applicationPath.empty())
    {
        serializer.WritePropertyName(L"applicationPath");
        serializer.WriteStringValue(m_applicationPath);
    }
    
    if (!m_applicationIdentifier.empty())
    {
        serializer.WritePropertyName(L"applicationIdentifier");
        serializer.WriteStringValue(m_applicationIdentifier);
    }
    
    if (!m_applicationBuild.empty())
    {
        serializer.WritePropertyName(L"applicationBuild");
        serializer.WriteStringValue(m_applicationBuild);
    }
    
    if (!m_exceptionType.empty())
    {
        serializer.WritePropertyName(L"exceptionType");
        serializer.WriteStringValue(m_exceptionType);
    }
    
    if (!m_exceptionCode.empty())
    {
        serializer.WritePropertyName(L"exceptionCode");
        serializer.WriteStringValue(m_exceptionCode);
    }
    
    if (!m_exceptionAddress.empty())
    {
        serializer.WritePropertyName(L"exceptionAddress");
        serializer.WriteStringValue(m_exceptionAddress);
    }
    
    if (!m_exceptionReason.empty())
    {
        serializer.WritePropertyName(L"exceptionReason");
        serializer.WriteStringValue(m_exceptionReason);
    }
}

