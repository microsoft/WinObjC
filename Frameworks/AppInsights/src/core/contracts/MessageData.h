#ifndef MESSAGEDATA_H
#define MESSAGEDATA_H

#include "../common/Common.h"
#include "../common/JsonWriter.h"
#include "../common/Nullable.h"
#include "../common/Serializer.h"
#include "Domain.h"
#include "SeverityLevel.h"
#include <map>
#include <string>
#include <vector>

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API MessageData : public Domain
		{
		private:
			int m_ver;
			std::wstring m_message;
			Nullable<SeverityLevel> m_severityLevel;
			std::map<std::wstring, std::wstring> m_properties;

		public:
			MessageData();
			MessageData(std::wstring envelopeName, std::wstring dataType);
			virtual ~MessageData();

			const int& GetVer() const { return m_ver; }
			void SetVer(const int& value) { m_ver = value; }

			const std::wstring& GetMessage() const { return m_message; }
			void SetMessage(const std::wstring& value) { m_message = value; }

			const Nullable<SeverityLevel>& GetSeverityLevel() const { return m_severityLevel; }
			void SetSeverityLevel(const Nullable<SeverityLevel>& value) { m_severityLevel = value; }

			const std::map<std::wstring, std::wstring>& GetProperties() const { return m_properties; }
			void SetProperties(const std::map<std::wstring, std::wstring>& value) { m_properties = value; }

			virtual void Serialize(Serializer& serializer) const;
		};
	}
}
#endif
