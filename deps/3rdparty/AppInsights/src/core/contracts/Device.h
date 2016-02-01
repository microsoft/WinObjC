#ifndef DEVICE_H
#define DEVICE_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API Device : public ISerializable
		{
		private:
			Nullable<std::wstring> m_id;
			Nullable<std::wstring> m_ip;
			Nullable<std::wstring> m_language;
			Nullable<std::wstring> m_locale;
			Nullable<std::wstring> m_model;
			Nullable<std::wstring> m_network;
			Nullable<std::wstring> m_oemName;
			Nullable<std::wstring> m_os;
			Nullable<std::wstring> m_osVersion;
			Nullable<std::wstring> m_roleInstance;
			Nullable<std::wstring> m_roleName;
			Nullable<std::wstring> m_screenResolution;
			Nullable<std::wstring> m_type;
			Nullable<std::wstring> m_machineName;

		public:
			Device();
			virtual ~Device();

			const Nullable<std::wstring>& GetId() const { return m_id; }
			void SetId(const Nullable<std::wstring>& value) { m_id = value; }

			const Nullable<std::wstring>& GetIp() const { return m_ip; }
			void SetIp(const Nullable<std::wstring>& value) { m_ip = value; }

			const Nullable<std::wstring>& GetLanguage() const { return m_language; }
			void SetLanguage(const Nullable<std::wstring>& value) { m_language = value; }

			const Nullable<std::wstring>& GetLocale() const { return m_locale; }
			void SetLocale(const Nullable<std::wstring>& value) { m_locale = value; }

			const Nullable<std::wstring>& GetModel() const { return m_model; }
			void SetModel(const Nullable<std::wstring>& value) { m_model = value; }

			const Nullable<std::wstring>& GetNetwork() const { return m_network; }
			void SetNetwork(const Nullable<std::wstring>& value) { m_network = value; }

			const Nullable<std::wstring>& GetOemName() const { return m_oemName; }
			void SetOemName(const Nullable<std::wstring>& value) { m_oemName = value; }

			const Nullable<std::wstring>& GetOs() const { return m_os; }
			void SetOs(const Nullable<std::wstring>& value) { m_os = value; }

			const Nullable<std::wstring>& GetOsVersion() const { return m_osVersion; }
			void SetOsVersion(const Nullable<std::wstring>& value) { m_osVersion = value; }

			const Nullable<std::wstring>& GetRoleInstance() const { return m_roleInstance; }
			void SetRoleInstance(const Nullable<std::wstring>& value) { m_roleInstance = value; }

			const Nullable<std::wstring>& GetRoleName() const { return m_roleName; }
			void SetRoleName(const Nullable<std::wstring>& value) { m_roleName = value; }

			const Nullable<std::wstring>& GetScreenResolution() const { return m_screenResolution; }
			void SetScreenResolution(const Nullable<std::wstring>& value) { m_screenResolution = value; }

			const Nullable<std::wstring>& GetType() const { return m_type; }
			void SetType(const Nullable<std::wstring>& value) { m_type = value; }

			const Nullable<std::wstring>& GetMachineName() const { return m_machineName; }
			void SetMachineName(const Nullable<std::wstring>& value) { m_machineName = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
