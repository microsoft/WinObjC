#include "Base.h"

using namespace ApplicationInsights::core;

Base::Base()
{
}

Base::~Base()
{
}

void Base::Serialize(Serializer& serializer) const
{
    if (!m_baseType.empty())
    {
        serializer.WritePropertyName(L"baseType");
        serializer.WriteStringValue(m_baseType);
    }
}

