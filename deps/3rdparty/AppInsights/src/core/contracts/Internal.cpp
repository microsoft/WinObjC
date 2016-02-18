#include "Internal.h"

using namespace ApplicationInsights::core;

Internal::Internal()
{
}

Internal::~Internal()
{
}

void Internal::Serialize(Serializer& serializer) const
{
    if (m_sdkVersion.HasValue())
    {
        serializer.WritePropertyName(L"ai.internal.sdkVersion");
        serializer.WriteStringValue(m_sdkVersion.GetValue());
    }
    
    if (m_agentVersion.HasValue())
    {
        serializer.WritePropertyName(L"ai.internal.agentVersion");
        serializer.WriteStringValue(m_agentVersion.GetValue());
    }
}

