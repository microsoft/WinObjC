#include "Envelope.h"

using namespace ApplicationInsights::core;

Envelope::Envelope() :
    m_ver(1),
    m_sampleRate(100.0)
{
}

Envelope::~Envelope()
{
}

void Envelope::Serialize(Serializer& serializer) const
{
    serializer.WritePropertyName(L"ver");
    serializer.WriteIntegerValue(m_ver);
    
    serializer.WritePropertyName(L"name");
    serializer.WriteStringValue(m_name);
    
    serializer.WritePropertyName(L"time");
    serializer.WriteStringValue(m_time);
    
    serializer.WritePropertyName(L"sampleRate");
    serializer.WriteDoubleValue(m_sampleRate);
    
    if (!m_seq.empty())
    {
        serializer.WritePropertyName(L"seq");
        serializer.WriteStringValue(m_seq);
    }
    
    if (!m_iKey.empty())
    {
        serializer.WritePropertyName(L"iKey");
        serializer.WriteStringValue(m_iKey);
    }
    
    serializer.WritePropertyName(L"flags");
    serializer.WriteIntegerValue(m_flags);
    
    if (!m_deviceId.empty())
    {
        serializer.WritePropertyName(L"deviceId");
        serializer.WriteStringValue(m_deviceId);
    }
    
    if (!m_os.empty())
    {
        serializer.WritePropertyName(L"os");
        serializer.WriteStringValue(m_os);
    }
    
    if (!m_osVer.empty())
    {
        serializer.WritePropertyName(L"osVer");
        serializer.WriteStringValue(m_osVer);
    }
    
    if (!m_appId.empty())
    {
        serializer.WritePropertyName(L"appId");
        serializer.WriteStringValue(m_appId);
    }
    
    if (!m_appVer.empty())
    {
        serializer.WritePropertyName(L"appVer");
        serializer.WriteStringValue(m_appVer);
    }
    
    if (!m_userId.empty())
    {
        serializer.WritePropertyName(L"userId");
        serializer.WriteStringValue(m_userId);
    }
    
    if (m_tags.size() > 0)
    {
        serializer.WritePropertyName(L"tags");
        serializer.BeginDictionaryValue();
        for (auto &it : m_tags)
        {
            serializer.WritePropertyName(it.first);
            serializer.WriteStringValue(it.second);
        }
        serializer.EndDictionaryValue();
    }
    
    serializer.WritePropertyName(L"data");
    serializer.WriteObjectValue(m_data);
}

