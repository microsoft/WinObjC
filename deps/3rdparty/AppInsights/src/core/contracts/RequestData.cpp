#include "RequestData.h"

using namespace ApplicationInsights::core;

RequestData::RequestData() :
    RequestData(L"Microsoft.ApplicationInsights.Request", L"RequestData")
{
}

RequestData::RequestData(std::wstring envelopeName, std::wstring baseType) :
    Domain(envelopeName, baseType),
    m_ver(2)
{
}

RequestData::~RequestData()
{
}

void RequestData::Serialize(Serializer& serializer) const
{
    Domain::Serialize(serializer);
    serializer.WritePropertyName(L"ver");
    serializer.WriteIntegerValue(m_ver);
    
    serializer.WritePropertyName(L"id");
    serializer.WriteStringValue(m_id);
    
    if (!m_name.empty())
    {
        serializer.WritePropertyName(L"name");
        serializer.WriteStringValue(m_name);
    }
    
    serializer.WritePropertyName(L"startTime");
    serializer.WriteStringValue(m_startTime);
    
    serializer.WritePropertyName(L"duration");
    serializer.WriteStringValue(m_duration);
    
    serializer.WritePropertyName(L"responseCode");
    serializer.WriteStringValue(m_responseCode);
    
    serializer.WritePropertyName(L"success");
    serializer.WriteBoolValue(m_success);
    
    if (!m_httpMethod.empty())
    {
        serializer.WritePropertyName(L"httpMethod");
        serializer.WriteStringValue(m_httpMethod);
    }
    
    if (!m_url.empty())
    {
        serializer.WritePropertyName(L"url");
        serializer.WriteStringValue(m_url);
    }
    
    if (m_properties.size() > 0)
    {
        serializer.WritePropertyName(L"properties");
        serializer.BeginDictionaryValue();
        for (auto &it : m_properties)
        {
            serializer.WritePropertyName(it.first);
            serializer.WriteStringValue(it.second);
        }
        serializer.EndDictionaryValue();
    }
    
    if (m_measurements.size() > 0)
    {
        serializer.WritePropertyName(L"measurements");
        serializer.BeginDictionaryValue();
        for (auto &it : m_measurements)
        {
            serializer.WritePropertyName(it.first);
            serializer.WriteDoubleValue(it.second);
        }
        serializer.EndDictionaryValue();
    }
}

