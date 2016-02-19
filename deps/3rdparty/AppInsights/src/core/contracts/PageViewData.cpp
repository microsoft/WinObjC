#include "PageViewData.h"

using namespace ApplicationInsights::core;

PageViewData::PageViewData() :
    PageViewData(L"Microsoft.ApplicationInsights.PageView", L"PageViewData")
{
}

PageViewData::PageViewData(std::wstring envelopeName, std::wstring baseType) :
    EventData(envelopeName, baseType)
{
}

PageViewData::~PageViewData()
{
}

void PageViewData::Serialize(Serializer& serializer) const
{
    EventData::Serialize(serializer);
    if (!m_url.empty())
    {
        serializer.WritePropertyName(L"url");
        serializer.WriteStringValue(m_url);
    }
    
    if (!m_duration.empty())
    {
        serializer.WritePropertyName(L"duration");
        serializer.WriteStringValue(m_duration);
    }
}

