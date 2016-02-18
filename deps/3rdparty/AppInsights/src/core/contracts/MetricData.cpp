#include "MetricData.h"

using namespace ApplicationInsights::core;

MetricData::MetricData() :
    MetricData(L"Microsoft.ApplicationInsights.Metric", L"MetricData")
{
}

MetricData::MetricData(std::wstring envelopeName, std::wstring baseType) :
    Domain(envelopeName, baseType),
    m_ver(2)
{
}

MetricData::~MetricData()
{
}

void MetricData::Serialize(Serializer& serializer) const
{
    Domain::Serialize(serializer);
    serializer.WritePropertyName(L"ver");
    serializer.WriteIntegerValue(m_ver);
    
    serializer.WritePropertyName(L"metrics");
    serializer.BeginArrayValue();
    for (auto &it : m_metrics)
    {
        serializer.WriteObjectValue(it);
    }
    serializer.EndArrayValue();
    
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

