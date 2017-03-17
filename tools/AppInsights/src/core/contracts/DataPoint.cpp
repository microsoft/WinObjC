#include "DataPoint.h"

using namespace ApplicationInsights::core;

DataPoint::DataPoint() :
    m_kind(Measurement)
{
}

DataPoint::~DataPoint()
{
}

void DataPoint::Serialize(Serializer& serializer) const
{
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
}

