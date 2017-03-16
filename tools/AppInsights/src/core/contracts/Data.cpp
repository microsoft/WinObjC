#include "Data.h"

using namespace ApplicationInsights::core;

Data::Data()
{
}

Data::~Data()
{
}

void Data::Serialize(Serializer& serializer) const
{
    Base::Serialize(serializer);
    serializer.WritePropertyName(L"baseData");
    serializer.WriteObjectValue(m_baseData);
}

