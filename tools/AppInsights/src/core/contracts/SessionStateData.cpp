#include "SessionStateData.h"

using namespace ApplicationInsights::core;

SessionStateData::SessionStateData() :
    SessionStateData(L"Microsoft.ApplicationInsights.SessionState", L"SessionStateData")
{
}

SessionStateData::SessionStateData(std::wstring envelopeName, std::wstring baseType) :
    Domain(envelopeName, baseType),
    m_ver(2),
    m_state(Start)
{
}

SessionStateData::~SessionStateData()
{
}

void SessionStateData::Serialize(Serializer& serializer) const
{
    Domain::Serialize(serializer);
    serializer.WritePropertyName(L"ver");
    serializer.WriteIntegerValue(m_ver);
    
    serializer.WritePropertyName(L"state");
    serializer.WriteIntegerValue(m_state);
}

