#include "CrashDataThreadFrame.h"

using namespace ApplicationInsights::core;

CrashDataThreadFrame::CrashDataThreadFrame()
{
}

CrashDataThreadFrame::~CrashDataThreadFrame()
{
}

void CrashDataThreadFrame::Serialize(Serializer& serializer) const
{
    serializer.WritePropertyName(L"address");
    serializer.WriteStringValue(m_address);
    
    if (!m_symbol.empty())
    {
        serializer.WritePropertyName(L"symbol");
        serializer.WriteStringValue(m_symbol);
    }
    
    if (m_registers.size() > 0)
    {
        serializer.WritePropertyName(L"registers");
        serializer.BeginDictionaryValue();
        for (auto &it : m_registers)
        {
            serializer.WritePropertyName(it.first);
            serializer.WriteStringValue(it.second);
        }
        serializer.EndDictionaryValue();
    }
}

