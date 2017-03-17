#include "User.h"
#include "../common/Utils.h"

using namespace ApplicationInsights::core;

#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Storage;
#endif
#endif

User::User()
{
}

User::~User()
{
}

const Nullable<std::wstring>& User::GetAccountAcquisitionDate()
{
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	if (values->HasKey("UserAcqDate"))
	{
		String^ sessionId = (String^)(values->Lookup("UserAcqDate"));
		std::wstring sessionIdwstr(sessionId->Data());
		m_accountAcquisitionDate.SetValue(sessionIdwstr);
	}
	else
	{
		m_accountAcquisitionDate.ClearValue();
	}
#endif
#endif
	return m_accountAcquisitionDate; 
}

void User::SetAccountAcquisitionDate(const Nullable<std::wstring>& value)
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	Platform::String^ acqDate = ref new String(value.GetValue().c_str());
	values->Insert("UserAcqDate", acqDate);
#endif
#endif
	m_accountAcquisitionDate = value; 
}

const Nullable<std::wstring>& User::GetAccountId()
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	if (values->HasKey("UserAcctId"))
	{
		String^ sessionId = (String^)(values->Lookup("UserAcctId"));
		std::wstring sessionIdwstr(sessionId->Data());
		m_accountId.SetValue(sessionIdwstr);
	}
	else
	{
		m_accountId.ClearValue();
	}
#endif
#endif
	return m_accountId; 
}

void User::SetAccountId(const Nullable<std::wstring>& value)
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	Platform::String^ acctId= ref new String(value.GetValue().c_str());
	values->Insert("UserAcctId", acctId);
#endif
#endif
	m_accountId = value; 
}

const Nullable<std::wstring>& User::GetUserAgent()
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	if (values->HasKey("UserAgent"))
	{
		String^ sessionId = (String^)(values->Lookup("UserAgent"));
		std::wstring sessionIdwstr(sessionId->Data());
		m_userAgent.SetValue(sessionIdwstr);
	}
	else
	{
		m_userAgent.ClearValue();
	}
#endif
#endif
	return m_userAgent; 
}

void User::SetUserAgent(const Nullable<std::wstring>& value)
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	Platform::String^ agent = ref new String(value.GetValue().c_str());
	values->Insert("UserAgent", agent);
#endif
#endif
	m_userAgent = value; 
}

const Nullable<std::wstring>& User::GetId()
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	if (values->HasKey("UserId"))
	{
		String^ sessionId = (String^)(values->Lookup("UserId"));
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

void User::SetId(const Nullable<std::wstring>& value)
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	Platform::String^ id = ref new String(value.GetValue().c_str());
	values->Insert("UserId", id);
#endif
#endif
	m_id = value; 
}

const Nullable<std::wstring>& User::GetStoreRegion()
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	if (values->HasKey("UserStoreRegion"))
	{
		String^ sessionId = (String^)(values->Lookup("UserStoreRegion"));
		std::wstring sessionIdwstr(sessionId->Data());
		m_storeRegion.SetValue(sessionIdwstr);
	}
	else
	{
		m_storeRegion.ClearValue();
	}
#endif
#endif
	return m_storeRegion; 
}

void User::SetStoreRegion(const Nullable<std::wstring>& value)
{ 
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
	auto values = Utils::GetLocalSettingsContainer();

	Platform::String^ storeRegion = ref new String(value.GetValue().c_str());
	values->Insert("UserStoreRegion", storeRegion);
#endif
#endif
	m_storeRegion = value; 
}

void User::Serialize(Serializer& serializer) const
{
    if (m_accountAcquisitionDate.HasValue())
    {
        serializer.WritePropertyName(L"ai.user.accountAcquisitionDate");
        serializer.WriteStringValue(m_accountAcquisitionDate.GetValue());
    }
    
    if (m_accountId.HasValue())
    {
        serializer.WritePropertyName(L"ai.user.accountId");
        serializer.WriteStringValue(m_accountId.GetValue());
    }
    
    if (m_userAgent.HasValue())
    {
        serializer.WritePropertyName(L"ai.user.userAgent");
        serializer.WriteStringValue(m_userAgent.GetValue());
    }
    
    if (m_id.HasValue())
    {
        serializer.WritePropertyName(L"ai.user.id");
        serializer.WriteStringValue(m_id.GetValue());
    }
    
    if (m_storeRegion.HasValue())
    {
        serializer.WritePropertyName(L"ai.user.storeRegion");
        serializer.WriteStringValue(m_storeRegion.GetValue());
    }
}

