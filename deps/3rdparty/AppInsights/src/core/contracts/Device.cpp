#include "Device.h"

using namespace ApplicationInsights::core;

Device::Device()
{
}

Device::~Device()
{
}

void Device::Serialize(Serializer& serializer) const
{
    if (m_id.HasValue())
    {
        serializer.WritePropertyName(L"ai.device.id");
        serializer.WriteStringValue(m_id.GetValue());
    }
    
    if (m_ip.HasValue())
    {
        serializer.WritePropertyName(L"ai.device.ip");
        serializer.WriteStringValue(m_ip.GetValue());
    }
    
    if (m_language.HasValue())
    {
        serializer.WritePropertyName(L"ai.device.language");
        serializer.WriteStringValue(m_language.GetValue());
    }
    
    if (m_locale.HasValue())
    {
        serializer.WritePropertyName(L"ai.device.locale");
        serializer.WriteStringValue(m_locale.GetValue());
    }
    
    if (m_model.HasValue())
    {
        serializer.WritePropertyName(L"ai.device.model");
        serializer.WriteStringValue(m_model.GetValue());
    }
    
    if (m_network.HasValue())
    {
        serializer.WritePropertyName(L"ai.device.network");
        serializer.WriteStringValue(m_network.GetValue());
    }
    
    if (m_oemName.HasValue())
    {
        serializer.WritePropertyName(L"ai.device.oemName");
        serializer.WriteStringValue(m_oemName.GetValue());
    }
    
    if (m_os.HasValue())
    {
        serializer.WritePropertyName(L"ai.device.os");
        serializer.WriteStringValue(m_os.GetValue());
    }
    
    if (m_osVersion.HasValue())
    {
        serializer.WritePropertyName(L"ai.device.osVersion");
        serializer.WriteStringValue(m_osVersion.GetValue());
    }
    
    if (m_roleInstance.HasValue())
    {
        serializer.WritePropertyName(L"ai.device.roleInstance");
        serializer.WriteStringValue(m_roleInstance.GetValue());
    }
    
    if (m_roleName.HasValue())
    {
        serializer.WritePropertyName(L"ai.device.roleName");
        serializer.WriteStringValue(m_roleName.GetValue());
    }
    
    if (m_screenResolution.HasValue())
    {
        serializer.WritePropertyName(L"ai.device.screenResolution");
        serializer.WriteStringValue(m_screenResolution.GetValue());
    }
    
    if (m_type.HasValue())
    {
        serializer.WritePropertyName(L"ai.device.type");
        serializer.WriteStringValue(m_type.GetValue());
    }
    
    if (m_machineName.HasValue())
    {
        serializer.WritePropertyName(L"ai.device.machineName");
        serializer.WriteStringValue(m_machineName.GetValue());
    }
}

