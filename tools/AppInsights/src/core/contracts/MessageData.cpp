#include "MessageData.h"

using namespace ApplicationInsights::core;

MessageData::MessageData() :
    MessageData(L"Microsoft.ApplicationInsights.Message", L"MessageData")
{
}

MessageData::MessageData(std::wstring envelopeName, std::wstring baseType) :
    Domain(envelopeName, baseType),
    m_ver(2)
{
}

MessageData::~MessageData()
{
}

void MessageData::Serialize(Serializer& serializer) const
{
    Domain::Serialize(serializer);
    serializer.WritePropertyName(L"ver");
    serializer.WriteIntegerValue(m_ver);
    
    serializer.WritePropertyName(L"message");
    serializer.WriteStringValue(m_message);
    
    if (m_severityLevel.HasValue())
    {
        serializer.WritePropertyName(L"severityLevel");
        serializer.WriteIntegerValue(m_severityLevel.GetValue());
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
}

