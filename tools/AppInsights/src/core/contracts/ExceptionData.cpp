#include "ExceptionData.h"

using namespace ApplicationInsights::core;

ExceptionData::ExceptionData() :
    ExceptionData(L"Microsoft.ApplicationInsights.Exception", L"ExceptionData")
{
}

ExceptionData::ExceptionData(std::wstring envelopeName, std::wstring baseType) :
    Domain(envelopeName, baseType),
    m_ver(2)
{
}

ExceptionData::~ExceptionData()
{
}

void ExceptionData::Serialize(Serializer& serializer) const
{
    Domain::Serialize(serializer);
    serializer.WritePropertyName(L"ver");
    serializer.WriteIntegerValue(m_ver);
    
    serializer.WritePropertyName(L"handledAt");
    serializer.WriteStringValue(m_handledAt);
    
    serializer.WritePropertyName(L"exceptions");
    serializer.BeginArrayValue();
    for (auto &it : m_exceptions)
    {
        serializer.WriteObjectValue(it);
    }
    serializer.EndArrayValue();
    
    if (m_severityLevel.HasValue())
    {
        serializer.WritePropertyName(L"severityLevel");
        serializer.WriteIntegerValue(m_severityLevel.GetValue());
    }
    
    if (!m_problemId.empty())
    {
        serializer.WritePropertyName(L"problemId");
        serializer.WriteStringValue(m_problemId);
    }
    
    serializer.WritePropertyName(L"crashThreadId");
    serializer.WriteIntegerValue(m_crashThreadId);
    
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

