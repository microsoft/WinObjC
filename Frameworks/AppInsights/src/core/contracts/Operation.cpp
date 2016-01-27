#include "Operation.h"

using namespace ApplicationInsights::core;

Operation::Operation()
{
}

Operation::~Operation()
{
}

void Operation::Serialize(Serializer& serializer) const
{
    if (m_id.HasValue())
    {
        serializer.WritePropertyName(L"ai.operation.id");
        serializer.WriteStringValue(m_id.GetValue());
    }
    
    if (m_name.HasValue())
    {
        serializer.WritePropertyName(L"ai.operation.name");
        serializer.WriteStringValue(m_name.GetValue());
    }
    
    if (m_parentId.HasValue())
    {
        serializer.WritePropertyName(L"ai.operation.parentId");
        serializer.WriteStringValue(m_parentId.GetValue());
    }
    
    if (m_rootId.HasValue())
    {
        serializer.WritePropertyName(L"ai.operation.rootId");
        serializer.WriteStringValue(m_rootId.GetValue());
    }
    
    if (m_syntheticSource.HasValue())
    {
        serializer.WritePropertyName(L"ai.operation.syntheticSource");
        serializer.WriteStringValue(m_syntheticSource.GetValue());
    }
    
    if (m_isSynthetic.HasValue())
    {
        serializer.WritePropertyName(L"ai.operation.isSynthetic");
        serializer.WriteStringValue(m_isSynthetic.GetValue());
    }
}

