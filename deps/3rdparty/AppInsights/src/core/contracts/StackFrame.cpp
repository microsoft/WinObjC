#include "StackFrame.h"

using namespace ApplicationInsights::core;

StackFrame::StackFrame()
{
}

StackFrame::~StackFrame()
{
}

void StackFrame::Serialize(Serializer& serializer) const
{
    serializer.WritePropertyName(L"level");
    serializer.WriteIntegerValue(m_level);
    
    serializer.WritePropertyName(L"method");
    serializer.WriteStringValue(m_method);
    
    if (!m_assembly.empty())
    {
        serializer.WritePropertyName(L"assembly");
        serializer.WriteStringValue(m_assembly);
    }
    
    if (!m_fileName.empty())
    {
        serializer.WritePropertyName(L"fileName");
        serializer.WriteStringValue(m_fileName);
    }
    
    serializer.WritePropertyName(L"line");
    serializer.WriteIntegerValue(m_line);
}

