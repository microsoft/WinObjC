#include "Application.h"

using namespace ApplicationInsights::core;

Application::Application()
{
}

Application::~Application()
{
}

void Application::Serialize(Serializer& serializer) const
{
    if (m_ver.HasValue())
    {
        serializer.WritePropertyName(L"ai.application.ver");
        serializer.WriteStringValue(m_ver.GetValue());
    }
    
    if (m_build.HasValue())
    {
        serializer.WritePropertyName(L"ai.application.build");
        serializer.WriteStringValue(m_build.GetValue());
    }
}

