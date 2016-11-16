#include "CrashData.h"

using namespace ApplicationInsights::core;

CrashData::CrashData() :
    CrashData(L"Microsoft.ApplicationInsights.Crash", L"CrashData")
{
}

CrashData::CrashData(std::wstring envelopeName, std::wstring baseType) :
    Domain(envelopeName, baseType),
    m_ver(2)
{
}

CrashData::~CrashData()
{
}

void CrashData::Serialize(Serializer& serializer) const
{
    Domain::Serialize(serializer);
    serializer.WritePropertyName(L"ver");
    serializer.WriteIntegerValue(m_ver);
    
    serializer.WritePropertyName(L"headers");
    serializer.WriteObjectValue(m_headers);
    
    if (m_threads.size() > 0)
    {
        serializer.WritePropertyName(L"threads");
        serializer.BeginArrayValue();
        for (auto &it : m_threads)
        {
            serializer.WriteObjectValue(it);
        }
        serializer.EndArrayValue();
    }
    
    if (m_binaries.size() > 0)
    {
        serializer.WritePropertyName(L"binaries");
        serializer.BeginArrayValue();
        for (auto &it : m_binaries)
        {
            serializer.WriteObjectValue(it);
        }
        serializer.EndArrayValue();
    }
}

