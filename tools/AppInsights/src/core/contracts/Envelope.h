#ifndef ENVELOPE_H
#define ENVELOPE_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include "Base.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API Envelope : public ISerializable
		{
		private:
			int m_ver;
			std::wstring m_name;
			std::wstring m_time;
			double m_sampleRate;
			std::wstring m_seq;
			std::wstring m_iKey;
			long m_flags;
			std::wstring m_deviceId;
			std::wstring m_os;
			std::wstring m_osVer;
			std::wstring m_appId;
			std::wstring m_appVer;
			std::wstring m_userId;
			std::map<std::wstring, std::wstring> m_tags;
			Base* m_data;

		public:
			Envelope();
			virtual ~Envelope();

			const int& GetVer() const { return m_ver; }
			void SetVer(const int& value) { m_ver = value; }

			const std::wstring& GetName() const { return m_name; }
			void SetName(const std::wstring& value) { m_name = value; }

			const std::wstring& GetTime() const { return m_time; }
			void SetTime(const std::wstring& value) { m_time = value; }

			const double& GetSampleRate() const { return m_sampleRate; }
			void SetSampleRate(const double& value) { m_sampleRate = value; }

			const std::wstring& GetSeq() const { return m_seq; }
			void SetSeq(const std::wstring& value) { m_seq = value; }

			const std::wstring& GetIKey() const { return m_iKey; }
			void SetIKey(const std::wstring& value) { m_iKey = value; }

			const long& GetFlags() const { return m_flags; }
			void SetFlags(const long& value) { m_flags = value; }

			const std::wstring& GetDeviceId() const { return m_deviceId; }
			void SetDeviceId(const std::wstring& value) { m_deviceId = value; }

			const std::wstring& GetOs() const { return m_os; }
			void SetOs(const std::wstring& value) { m_os = value; }

			const std::wstring& GetOsVer() const { return m_osVer; }
			void SetOsVer(const std::wstring& value) { m_osVer = value; }

			const std::wstring& GetAppId() const { return m_appId; }
			void SetAppId(const std::wstring& value) { m_appId = value; }

			const std::wstring& GetAppVer() const { return m_appVer; }
			void SetAppVer(const std::wstring& value) { m_appVer = value; }

			const std::wstring& GetUserId() const { return m_userId; }
			void SetUserId(const std::wstring& value) { m_userId = value; }

			const std::map<std::wstring, std::wstring>& GetTags() const { return m_tags; }
			void SetTags(const std::map<std::wstring, std::wstring>& value) { m_tags = value; }

			Base* GetData() const { return m_data; }
			void SetData(Base &value) { m_data = &value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
