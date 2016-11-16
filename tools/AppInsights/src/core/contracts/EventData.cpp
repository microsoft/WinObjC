#include "EventData.h"

using namespace ApplicationInsights::core;

EventData::EventData() :
    EventData(L"Microsoft.ApplicationInsights.Event", L"EventData")
{
}

EventData::EventData(std::wstring envelopeName, std::wstring baseType) :
    Domain(envelopeName, baseType),
    m_ver(2)
{
}

EventData::~EventData()
{
}

void EventData::Serialize(Serializer& serializer) const
{
    Domain::Serialize(serializer);
    serializer.WritePropertyName(L"ver");
    serializer.WriteIntegerValue(m_ver);
    
    serializer.WritePropertyName(L"name");
    serializer.WriteStringValue(m_name);
    
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

