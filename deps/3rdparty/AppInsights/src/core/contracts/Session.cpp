#include "Session.h"
#include "../common/Utils.h"

using namespace ApplicationInsights::core;

#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Storage;
#endif
#endif

Session::Session()
{
}

Session::~Session()
{
}

const Nullable<std::wstring>& Session::GetId()
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	if (values->HasKey("SessionId"))
	{
		String^ sessionId = (String^)(values->Lookup("SessionId"));
		std::wstring sessionIdwstr(sessionId->Data());
		m_id.SetValue(sessionIdwstr);
	}
	else
	{
		m_id.ClearValue();
	}
#endif
#endif
	return m_id;
}

void Session::SetId(const Nullable<std::wstring>& value)
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	Platform::String^ id = ref new String(value.GetValue().c_str());
	values->Insert("SessionId", id);
#endif
#endif
	m_id = value; 
}

const Nullable<std::wstring>& Session::GetIsFirst()
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	if (values->HasKey("SessionIsFirst"))
	{
		String^ isFirst = (String^)(values->Lookup("SessionIsFirst"));
		std::wstring isFirstWstr(isFirst->Data());
		m_isFirst.SetValue(isFirstWstr);
	}
	else
	{
		m_isFirst.ClearValue();
	}
#endif
#endif
	return m_isFirst; 
}

void Session::SetIsFirst(const Nullable<std::wstring>& value)
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	Platform::String^ isFirst = ref new String(value.GetValue().c_str());
	values->Insert("SessionIsFirst", isFirst);
#endif
#endif
	m_isFirst = value; 
}

const Nullable<std::wstring>& Session::GetIsNew()
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	if (values->HasKey("SessionIsNew"))
	{
		String^ isNew = (String^)(values->Lookup("SessionIsNew"));
		std::wstring isNewWstr(isNew->Data());
		m_isNew.SetValue(isNewWstr);
	}
	else
	{
		m_isNew.ClearValue();
	}
#endif
#endif
	return m_isNew; 
}

void Session::SetIsNew(const Nullable<std::wstring>& value)
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	Platform::String^ isNew = ref new String(value.GetValue().c_str());
	values->Insert("SessionIsNew", isNew);
#endif
#endif
	m_isNew = value; 
}

void Session::Serialize(Serializer& serializer) const
{
    if (m_id.HasValue())
    {
        serializer.WritePropertyName(L"ai.session.id");
        serializer.WriteStringValue(m_id.GetValue());
    }
    
    if (m_isFirst.HasValue())
    {
        serializer.WritePropertyName(L"ai.session.isFirst");
        serializer.WriteStringValue(m_isFirst.GetValue());
    }
    
    if (m_isNew.HasValue())
    {
        serializer.WritePropertyName(L"ai.session.isNew");
        serializer.WriteStringValue(m_isNew.GetValue());
    }
}

