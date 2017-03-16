#include "PageViewPerfData.h"

using namespace ApplicationInsights::core;

PageViewPerfData::PageViewPerfData() :
    PageViewPerfData(L"Microsoft.ApplicationInsights.PageViewPerf", L"PageViewPerfData")
{
}

PageViewPerfData::PageViewPerfData(std::wstring envelopeName, std::wstring baseType) :
    PageViewData(envelopeName, baseType)
{
}

PageViewPerfData::~PageViewPerfData()
{
}

void PageViewPerfData::Serialize(Serializer& serializer) const
{
    PageViewData::Serialize(serializer);
    if (!m_perfTotal.empty())
    {
        serializer.WritePropertyName(L"perfTotal");
        serializer.WriteStringValue(m_perfTotal);
    }
    
    if (!m_networkConnect.empty())
    {
        serializer.WritePropertyName(L"networkConnect");
        serializer.WriteStringValue(m_networkConnect);
    }
    
    if (!m_sentRequest.empty())
    {
        serializer.WritePropertyName(L"sentRequest");
        serializer.WriteStringValue(m_sentRequest);
    }
    
    if (!m_receivedResponse.empty())
    {
        serializer.WritePropertyName(L"receivedResponse");
        serializer.WriteStringValue(m_receivedResponse);
    }
    
    if (!m_domProcessing.empty())
    {
        serializer.WritePropertyName(L"domProcessing");
        serializer.WriteStringValue(m_domProcessing);
    }
}

