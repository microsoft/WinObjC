#include "Location.h"

using namespace ApplicationInsights::core;

Location::Location()
{
}

Location::~Location()
{
}

void Location::Serialize(Serializer& serializer) const
{
    if (m_ip.HasValue())
    {
        serializer.WritePropertyName(L"ai.location.ip");
        serializer.WriteStringValue(m_ip.GetValue());
    }
}

