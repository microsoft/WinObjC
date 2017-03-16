#include "Domain.h"

using namespace ApplicationInsights::core;

Domain::Domain(std::wstring envelopeName, std::wstring baseType) :
    m_envelopeName(envelopeName),
    m_baseType(baseType)
{
}

Domain::~Domain()
{
}

void Domain::Serialize(Serializer& serializer) const
{
}

