#include "ExceptionDetails.h"

using namespace ApplicationInsights::core;

ExceptionDetails::ExceptionDetails() :
    m_hasFullStack(true)
{
}

ExceptionDetails::~ExceptionDetails()
{
}

void ExceptionDetails::Serialize(Serializer& serializer) const
{
    serializer.WritePropertyName(L"id");
    serializer.WriteIntegerValue(m_id);
    
    serializer.WritePropertyName(L"outerId");
    serializer.WriteIntegerValue(m_outerId);
    
    serializer.WritePropertyName(L"typeName");
    serializer.WriteStringValue(m_typeName);
    
    serializer.WritePropertyName(L"message");
    serializer.WriteStringValue(m_message);
    
    serializer.WritePropertyName(L"hasFullStack");
    serializer.WriteBoolValue(m_hasFullStack);
    
    if (!m_stack.empty())
    {
        serializer.WritePropertyName(L"stack");
        serializer.WriteStringValue(m_stack);
    }
    
    if (m_parsedStack.size() > 0)
    {
        serializer.WritePropertyName(L"parsedStack");
        serializer.BeginArrayValue();
        for (auto &it : m_parsedStack)
        {
            serializer.WriteObjectValue(it);
        }
        serializer.EndArrayValue();
    }
}

