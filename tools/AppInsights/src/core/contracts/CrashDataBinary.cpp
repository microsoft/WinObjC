#include "CrashDataBinary.h"

using namespace ApplicationInsights::core;

CrashDataBinary::CrashDataBinary()
{
}

CrashDataBinary::~CrashDataBinary()
{
}

void CrashDataBinary::Serialize(Serializer& serializer) const
{
    if (!m_startAddress.empty())
    {
        serializer.WritePropertyName(L"startAddress");
        serializer.WriteStringValue(m_startAddress);
    }
    
    if (!m_endAddress.empty())
    {
        serializer.WritePropertyName(L"endAddress");
        serializer.WriteStringValue(m_endAddress);
    }
    
    if (!m_name.empty())
    {
        serializer.WritePropertyName(L"name");
        serializer.WriteStringValue(m_name);
    }
    
    serializer.WritePropertyName(L"cpuType");
    serializer.WriteDoubleValue(m_cpuType);
    
    serializer.WritePropertyName(L"cpuSubType");
    serializer.WriteDoubleValue(m_cpuSubType);
    
    if (!m_uuid.empty())
    {
        serializer.WritePropertyName(L"uuid");
        serializer.WriteStringValue(m_uuid);
    }
    
    if (!m_path.empty())
    {
        serializer.WritePropertyName(L"path");
        serializer.WriteStringValue(m_path);
    }
}

