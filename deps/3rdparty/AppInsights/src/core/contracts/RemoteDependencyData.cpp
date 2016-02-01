#include "RemoteDependencyData.h"

using namespace ApplicationInsights::core;

RemoteDependencyData::RemoteDependencyData() :
    RemoteDependencyData(L"Microsoft.ApplicationInsights.RemoteDependency", L"RemoteDependencyData")
{
}

RemoteDependencyData::RemoteDependencyData(std::wstring envelopeName, std::wstring baseType) :
    Domain(envelopeName, baseType),
    m_ver(2),
    m_kind(Measurement),
    m_dependencyKind(Other),
    m_success(true),
    m_dependencySource(Undefined)
{
}

RemoteDependencyData::~RemoteDependencyData()
{
}

void RemoteDependencyData::Serialize(Serializer& serializer) const
{
    Domain::Serialize(serializer);
    serializer.WritePropertyName(L"ver");
    serializer.WriteIntegerValue(m_ver);
    
    serializer.WritePropertyName(L"name");
    serializer.WriteStringValue(m_name);
    
    serializer.WritePropertyName(L"kind");
    serializer.WriteIntegerValue(m_kind);
    
    serializer.WritePropertyName(L"value");
    serializer.WriteDoubleValue(m_value);
    
    if (m_count.HasValue())
    {
        serializer.WritePropertyName(L"count");
        serializer.WriteIntegerValue(m_count.GetValue());
    }
    
    if (m_min.HasValue())
    {
        serializer.WritePropertyName(L"min");
        serializer.WriteDoubleValue(m_min.GetValue());
    }
    
    if (m_max.HasValue())
    {
        serializer.WritePropertyName(L"max");
        serializer.WriteDoubleValue(m_max.GetValue());
    }
    
    if (m_stdDev.HasValue())
    {
        serializer.WritePropertyName(L"stdDev");
        serializer.WriteDoubleValue(m_stdDev.GetValue());
    }
    
    serializer.WritePropertyName(L"dependencyKind");
    serializer.WriteIntegerValue(m_dependencyKind);
    
    if (m_success.HasValue())
    {
        serializer.WritePropertyName(L"success");
        serializer.WriteBoolValue(m_success.GetValue());
    }
    
    if (m_async.HasValue())
    {
        serializer.WritePropertyName(L"async");
        serializer.WriteBoolValue(m_async.GetValue());
    }
    
    serializer.WritePropertyName(L"dependencySource");
    serializer.WriteIntegerValue(m_dependencySource);
    
    if (!m_commandName.empty())
    {
        serializer.WritePropertyName(L"commandName");
        serializer.WriteStringValue(m_commandName);
    }
    
    if (!m_dependencyTypeName.empty())
    {
        serializer.WritePropertyName(L"dependencyTypeName");
        serializer.WriteStringValue(m_dependencyTypeName);
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

