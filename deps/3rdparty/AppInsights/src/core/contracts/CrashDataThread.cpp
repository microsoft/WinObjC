#include "CrashDataThread.h"

using namespace ApplicationInsights::core;

CrashDataThread::CrashDataThread()
{
}

CrashDataThread::~CrashDataThread()
{
}

void CrashDataThread::Serialize(Serializer& serializer) const
{
    serializer.WritePropertyName(L"id");
    serializer.WriteIntegerValue(m_id);
    
    if (m_frames.size() > 0)
    {
        serializer.WritePropertyName(L"frames");
        serializer.BeginArrayValue();
        for (auto &it : m_frames)
        {
            serializer.WriteObjectValue(it);
        }
        serializer.EndArrayValue();
    }
}

